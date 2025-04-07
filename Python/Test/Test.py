# U = 220
# cosa = 0.5
#
# ret = 1.17 * U * cosa
#
# print(ret)

# Io = 0.2
#
# Uin = 33
# Uo = 100
#
# D = 1 - Uin / Uo
#
# Il = Io / (1 - D)
#
# Delta_Il = D * (1 - D) * Uin / 184.25 * (1 / 100000)
#
# print(Il)
# print(Delta_Il)

# Io = 0.2
# Uin = 27
# Uo = 100
#
# k = Uo / Uin
# L = 184.25
# D = 1 - Uin / Uo
# T = 10
#
# Imax = k * Io + (Uin / (2 * L)) * D * T
# Imin = k * Io - (Uin / (2 * L)) * D * T
#
# print(Imax)
# print(Imin)

Uin = 33
Uo = 100
I = 0.2 * 0.2 * 3

L = Uin / I * (1 - (Uin / Uo))

print(L)
