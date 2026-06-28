int tolower(int c)
{
    (unsigned char)(c);
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}