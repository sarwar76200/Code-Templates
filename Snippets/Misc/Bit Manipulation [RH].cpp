long long int get_bit(long long int n, long long int pos)
{
    return (n & (1 << pos));
}
long long int set_bit(long long int n, long long int pos)
{
    return (n | (1 << pos));
}
long long int clear_bit(long long int n, long long int pos)
{
    return (n & (~(1 << pos)));
}
long long int updater_bit(long long int n, long long int pos, long long int value)
{
    n = n & (~(1 << pos));
    return (n | (1 << value));
}