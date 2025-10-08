#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card;

    // Get card number
    do
    {
        card = get_long("number: ");
    }
    while (card < 0);

    // Count digits
    int length = 0;
    long tempcard = card;
    while (tempcard > 0)
    {
        length++;
        tempcard /= 10;
    }

    // Check length
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Luhn's algorithm
    int sum1 = 0, sum2 = 0;
    tempcard = card;
    int position = 0;

    while (tempcard > 0)
    {
        int digit = tempcard % 10;

        if (position % 2 == 0)
        {
            sum1 += digit;
        }
        else
        {
            int doubled = digit * 2;
            sum2 += doubled / 10 + doubled % 10;
        }

        tempcard /= 10;
        position++;
    }

    int total = sum1 + sum2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get first two digits
    long start = card;
    while (start >= 100)
    {
        start /= 10;
    }

    // Card type check
    if ((length == 13 || length == 16) && (start / 10 == 4))
    {
        printf("VISA\n");
    }
    else if (length == 16 && (start >= 51 && start <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (length == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

