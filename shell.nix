with import <nixpkgs> {};

let
  yosys = pkgs.yosys.overrideAttrs {
#    src = ../yosys;
  };
in
mkShell {
  nativeBuildInputs = [pkgs.pkgsCross.riscv32-embedded.pkgsBuildHost.gcc verilog verilator yosys nextpnrWithGui python3Packages.apycula graphviz openfpgaloader xdot];
} 
