vector <bool> isprime(1000050, true);
vector <int> primelist;
void sieve()
{
    isprime[1] = false;
    isprime[0] = false;
    isprime[2] = true;
    for (int i = 4; i <= 1000050; i += 2)
    {
        isprime[i] = false;
    }
    for (long long int i = 3; i * i <= 1000050; i++)
    {
        for (long long int j = i * i; j <= 1000050; j = j + i + i)
        {
            isprime[j] = false;
        }
    }
    for (int i = 1; i <= 1000050; i++)
    {
        if (isprime[i])
        {
            primelist.push_back(i);
        }
    }
}