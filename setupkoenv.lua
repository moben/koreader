local ffi = require("ffi")

local has_libkoreader, libkoreader = pcall(require, "libkoreader")
print('has libkoreader? ' .. (has_libkoreader and 'yes' or 'no'))
if has_libkoreader then
    for k, v in pairs(libkoreader.preloads)
    do
        package.preload[k] = package.loadlib(libkoreader.library, v)
    end
end

local lib_search_path
local lib_version_format
if ffi.os == "Linux" and os.getenv("IS_ANDROID") then
    -- Note: our libraries are not versioned on Android.
    lib_search_path = "libs/lib?.so"
    lib_version_format = "%s.so"
elseif ffi.os == "Linux" then
    -- Note: we need the `libs/lib?` variant for versioned libraries
    -- (e.g. `ffi.loadlib("utf8proc", 2)` will trigger a search for
    -- `utf8proc.so.2` on Linux).
    lib_search_path = "libs/lib?;libs/lib?.so"
    lib_version_format = "%s.so.%s"
elseif ffi.os == "OSX" then
    lib_search_path = "libs/lib?.dylib"
    lib_version_format = "%s.%s.dylib"
end

local function libname(name, version)
    return version and string.format(lib_version_format, name, version) or name
end

local function findlib(...)
    local name, version = ...
    if not name then
        return
    end
    print("ffi.findlib: " .. name .. (version and ("." .. version) or ""))
    if has_libkoreader then
        local key = version and (name .. '.' .. version) or name
        if libkoreader.redirects[key] then
            return libkoreader.library
        end
    end
    local lib = libname(name, version)
    local path = package.searchpath(lib, lib_search_path, "/", "/")
    if path then
        return path
    end
    return findlib(select(3, ...))
end

local ffi_load = ffi.load
if ffi.os == "Linux" and os.getenv("IS_ANDROID") then
    ffi.load = function(l)
        local lib = findlib(l) or libname(l)
        print("ffi.load: " .. lib)
        return ffi_load(lib)
    end
    ffi.loadlib = function(...)
        local lib = findlib(...) or libname(...)
        print("ffi.load: " .. lib)
        return ffi_load(lib)
    end
else
    ffi.load = function(lib)
        print("ffi.load: " .. lib)
        return ffi_load(lib)
    end
    ffi.loadlib = function(...)
        local lib = findlib(...) or libname(...)
        return ffi.load(lib)
    end
end
