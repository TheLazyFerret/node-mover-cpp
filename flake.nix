{
  description = "C++ clang based project flake.";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      pkgs = nixpkgs.legacyPackages."x86_64-linux";
    in
  {
    devShells."x86_64-linux".default = pkgs.mkShell {
      packages = with pkgs; [
        gcc
        clang
        clang-tools
        cmake
        gnumake
      ];
      inputsFrom = [];
      shellHook = ''
        clang++ --version
      '';
      CC="clang";
      CXX="clang++";
    };
  };
}
