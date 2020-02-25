using System;

namespace _1._1
{
    class Program
    {
        static void Main(string[] args)
        {
            string enter = Console.ReadLine();
            int factorial = Convert.ToInt32(enter);
            if (factorial > 12)
            {
                Console.WriteLine("Over the limit number");
            }
            else
            {
                int helper = factorial;
                while (helper > 1)
                {
                    helper--;
                    factorial = factorial * helper;
                }
                Console.WriteLine(factorial);
            }
        }
    }
}
