#!/bin/zsh

for i in {1..100}; do printf "%s " $((RANDOM % 10 + 1)); done > numbers

