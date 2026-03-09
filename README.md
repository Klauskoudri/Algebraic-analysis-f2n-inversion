# Algebraic Analysis of the Inversion Mapping over F₂⁸

## Introduction

This project investigates the algebraic properties of the inversion mapping 
over F₂⁸, which constitutes the nonlinear core of the S-Box used in the 
Advanced Encryption Standard (AES).

The study focuses on:
- Explicit construction of F₂⁸ and from-scratch implementation of its arithmetic
- Algebraic degree of the inversion mapping x ↦ x²⁵⁴
- Differential uniformity
- Nonlinearity
- Invariance under affine equivalence

The aim is to provide a rigorous theoretical analysis supported by 
experimental validation in C and Python.

## Repository Structure

- `report/` : LaTeX source and compiled PDF report
- `code/c/` : C implementation of F₂⁸ arithmetic and experiments
- `code/python/` : Python scripts for analysis and verification
- `docs/` : theoretical notes and derivations

## Key Results

- Algebraic degree of inversion mapping = 7
- Differential uniformity = 4
- Nonlinearity confirmed numerically
- Invariance under affine equivalence validated
