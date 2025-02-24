#!/bin/bash

set -e  # Exit immediately if a command fails
set -o pipefail  # Exit if any command in a pipeline fails

VCPKG_DIR="external/vcpkg"

# Ensure git submodule is added and initialized
echo "Cloning vcpkg as a submodule..."
git submodule add https://github.com/microsoft/vcpkg.git $VCPKG_DIR || true
git submodule update --init --recursive

# Navigate to vcpkg directory
cd $VCPKG_DIR

# Force use of GCC-12 if available
if command -v gcc-12 &> /dev/null && command -v g++-12 &> /dev/null; then
    export CC=gcc-12
    export CXX=g++-12
    echo "Using GCC-12 for compilation."
else
    echo "GCC-12 not found, using default compiler."
fi

# Bootstrap vcpkg
echo "Bootstrapping vcpkg..."
./bootstrap-vcpkg.sh

echo "Installing glad..."
./vcpkg install glad

echo "vcpkg setup complete!"
