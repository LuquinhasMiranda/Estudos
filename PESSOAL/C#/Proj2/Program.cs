using System;
using System.Threading;

namespace Proj2
{
    class Program
    {
        static int[] lista;
        static void Main(string[] args)
        {
            lista = new int[]{0,0,0,0}; 

            Thread t1 = new Thread(delegate(){ funcao(100, 0); });
            t1.Start();
            Thread t2 = new Thread(delegate(){ funcao(200, 1); });
            t2.Start();
            Thread t3 = new Thread(delegate(){ funcao(300, 2); });
            t3.Start();
            Thread t4 = new Thread(delegate(){ funcao(150, 3); });
            t4.Start();

            while (t1.IsAlive || t2.IsAlive || t3.IsAlive || t4.IsAlive)
            {
                Thread.Sleep(1000);
            }

            foreach (int item in lista)
            {
                Console.WriteLine(item);
            }
        }

        static void funcao(int numero, int pos) {
            Thread.Sleep(numero*10);
            lista[pos] = numero;
            Console.WriteLine("TH" + pos.ToString() + " finished.");
        }
    }
}
