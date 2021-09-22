using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1 = Int16.Parse(Console.ReadLine());
            Calc(num1);
        }

        static void Calc(float cache) 
        {
            char op = Console.ReadLine()[0];
            int num2 = Int16.Parse(Console.ReadLine());

            switch (op)
            {
                case '+':
                    cache = cache + num2;
                    break;
                case '-':
                    cache = cache - num2;
                    break;
                case '*':
                    cache = cache * num2;
                    break;
                case '/':
                    cache = cache / num2;
                    break;
                default:
                    Console.WriteLine("ERRO");
                    return;
            }
            Console.WriteLine("=\n" + cache.ToString());
            Calc(cache);
        }
    }
}
