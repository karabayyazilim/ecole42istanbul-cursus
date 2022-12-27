#!/bin/bash

git clone https://github.com/amir20/dozzle.git dozzle

mv package.json dozzle/package.json

cd dozzle/

pnpm install

pnpm dev