# RSA-Encryption

## Goal Intended
- Implement recursive gcd function
- Implement Inverse Module function
- Implement generateKeys function
- Implement encrypt and decrypt function

## To determine your key pairs
- Find two primes (p & q) randomly, defining ‘n’ as n = p*q
- Define φ(n) = (p-1) * (q-1)
- Choose e at random, but such that e<φ(n), and e & φ(n) are coprime (they share no common
factors, i.e: GCD(e, φ(n)) = 1 )
- Define d as the Modular Multiplicative Inverse of e mod φ(n), such that e*d ≡ 1 (mod φ(n) )
- Publicise (e, n) as the public key, keep (d, n) as your private key.
(Discard φ(n), p, q)

***For use of the created keys, both ends of RSA(encryption and decryption) are forms of modular
exponentiation, either ‘me mod n = c’ or ‘cd mod n = m’, which are both very similar.
(Note that ‘n’ is used in both processes, while ‘e’ and ‘d’ are exclusive and inverses of each other)
Encryption:
Given: ‘m’(an integer), (e, n) (the public key of the pair)
Return: ‘c’, a ciphered integer defined as c = (me) mod n
Decryption:
Given: ‘c’(a ciphered integer formed from the public key), (d, n) (the private key of the pair)
Return: ‘m’***
