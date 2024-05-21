{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
  # calling a function from `flake-utils` that takes a lambda
  # that takes the system we're targetting
    flake-utils.lib.eachDefaultSystem (
      system: let
        # no need to define `system` anymore
        name = "simple";
        src = ./.;
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        devShells.default = (import ./shell.nix) {pkgs = pkgs;};
      }
    );
}
