{
  nixpkgsSource ? (builtins.fetchTarball {
    name = "nixpkgs";
    url = "https://github.com/NixOS/nixpkgs/archive/nixpkgs-unstable.tar.gz";
    sha256 = "sha256:1xbvd82w5ry8bl0df48algb35wj4l2p1lmpaaadp0da1arvnn61f";
  }),
  pkgs ? import nixpkgsSource {
    config.allowUnfree = true;
  },

}:

let
  cmakeVersion = "3.10.2";

  buildToolsVersion = "30.0.2";
  # Use cmakeVersion when you define androidComposition
  # androidComposition = pkgs.androidenv.androidPkgs_9_0;
  androidComposition = pkgs.androidenv.composeAndroidPackages {
    cmdLineToolsVersion = "8.0";
    toolsVersion = "26.1.1";
    platformToolsVersion = "34.0.1";
    buildToolsVersions = [ buildToolsVersion ];
    # includeEmulator = true;
    emulatorVersion = "33.1.6";
    platformVersions = [ "30" ];
    includeSources = false;
    includeSystemImages = false;
    systemImageTypes = [ "google_apis_playstore" ];
    abiVersions = [ "arm64-v8a" "armeabi-v7a" ];
    # cmakeVersions = [ "3.10.2" ];
    includeNDK = true;
    ndkVersions = ["22.0.7026061"];
    useGoogleAPIs = false;
    useGoogleTVAddOns = false;
    includeExtras = [
      # "extras;google;gcm"
    ];
  };

in
pkgs.mkShell rec {
  buildInputs = with pkgs; [
    freetype
    libpng
    libxkbcommon
    mesa
    openjdk11
    SDL2
    vulkan-headers
    vulkan-loader
    wayland
    wayland-protocols
    xorg.libXcursor
    xorg.libXext
    xorg.libXi
    xorg.libXrandr
  ];
  nativeBuildInputs = with pkgs; [
    autoconf
    automake
    bash
    ccache
    chrpath
    cmake
    gcc_multi
    git
    gnumake
    gnutar
    libgcc
    libtool
    lld_16
    meson
    nasm
    ninja
    pkg-config
    python3
  ];
  ANDROID_SDK_ROOT = "${androidComposition.androidsdk}/libexec/android-sdk";
  ANDROID_NDK_ROOT = "${ANDROID_SDK_ROOT}/ndk-bundle";

  GRADLE_OPTS = "-Dorg.gradle.project.android.aapt2FromMavenOverride=${ANDROID_SDK_ROOT}/build-tools/${buildToolsVersion}/aapt2";
  CC_FOR_BUILD="gcc";

  # Use the same cmakeVersion here
  shellHook = ''
    export PATH="$(echo "$ANDROID_SDK_ROOT/cmake/${cmakeVersion}".*/bin):$PATH"
    export CC_FOR_BUILD=gcc
  '';
}
