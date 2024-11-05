# -*- coding: utf-8 -*-
# ---
# jupyter:
#   jupytext:
#     text_representation:
#       extension: .jl
#       format_name: hydrogen
#       format_version: '1.3'
#       jupytext_version: 1.16.4
#   kernelspec:
#     display_name: Julia 1.11.1
#     language: julia
#     name: julia-1.11
# ---

# %% [markdown]
# ## Markdown Text Dude
# %%
println("Hola aaaaaaaa")
# %%
my_answer = 42
typeof(my_answer)
# %%
my_pi = 3.14159
typeof(my_pi)
# %%
😄 = 1
typeof(😄)
# %%
sum = 3 + 7
difference = 10 - 3
product = 20 * 5
quotient = 100 / 10
power = 10 ^ 2
modulus = 101 % 2
# %%
days = 365
days_float = convert(Float64, days)
# %%
@assert days == 365
@assert days_float == 365.0
# %%
# Double quotes cast type to string while single quotes cast to char
convert(Int64, "1")
parse(Int64, "1")
# %%
typeof('1')
# %%

