using System;
using System.Collections.Generic;

namespace Proj1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Book> book_list = new List<Book>();
            book_list.Add(new Book("Fogo", "Luquinhas", 400));
            book_list.Add(new Book("Agua", "Lucas", 696));
            book_list.Add(new Book("Terra", "Luquinhas", 234));
            
            foreach (Book book in book_list)
            {
                Console.WriteLine(book.name + " -" + book.author + " (" + book.pages.ToString() + " pages)");
            }

        }
    }
}
