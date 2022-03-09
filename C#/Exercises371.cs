using System;

namespace AdsAndSupport
{
    class Exercises371
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int test = 1; test <= t; test++)
            {
                int n = int.Parse(Console.ReadLine());
                if (n < 6)
                {
                    Console.WriteLine($"Test {test}: NO");
                }
                else
                {
                    int sum = 1;
                    int bound = (int)Math.Sqrt(n);
                    for (int j = 2; j <= bound; j++)
                    {
                        if (n % j == 0)
                        {
                            if (n / j == j)
                            {
                                sum += j;
                            }
                            else
                            {
                                sum += j;
                                sum += n / j;
                            }
                        }
                    }
                    Console.WriteLine($"Test {test}: {(n == sum ? "YES" : "NO")}");
                }
            }

        }
    }
}
