
# Greater Common Divisore
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

p=99871
q=99719

n = p * q
phi = (p-1) * (q-1)

# Encryption Exponet
e = 2
while e < phi:
    if gcd(e, phi) == 1:
        break
    e += 1

# Dectyption Exponent Using Extended Euclidean Algorithm
d = pow(e, -1, phi)

print(f'n: {n}')

message = 3242353

print(f"message before encryption: {message}")


# Encryption
c = pow(message, e, n)

print(f"Message after encryption: {c}")


# Dncryption
m = pow(c, d, n)

print(f'Message after decryption: {m}')
