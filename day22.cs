using System;
using System.Collections.Generic;

namespace aocday22
{
    class Program
    {
        static void MakeMove(Queue<int> p1, Queue<int> p2)
        {
            int p1Card = p1.Dequeue();
            int p2Card = p2.Dequeue();
            if (p1Card > p2Card)
            {
                p1.Enqueue(p1Card);
                p1.Enqueue(p2Card);
                return;
            }

            p2.Enqueue(p2Card);
            p2.Enqueue(p1Card);
        }

        static int CountScore(Queue<int> hand)
        {
            int multiplier = hand.Count;
            int score = 0;

            while(multiplier > 0)
            {
                score += multiplier * hand.Dequeue();
                multiplier--;
            }

            return score;
        }

        static void ReadLines(out Queue<int> p1hand, out Queue<int> p2hand)
        {
            List<int> input = new List<int>();

            string line;
            while ((line = Console.ReadLine()) != null)
            {
                int result;
                if (int.TryParse(line, out result))
                {
                    input.Add(result);
                }
            }

            int deck_size = input.Count;

            p1hand = new Queue<int>();
            p2hand = new Queue<int>();

            for (int i = 0; i < deck_size / 2; i++)
                p1hand.Enqueue(input[i]);

            for (int i = deck_size / 2; i < input.Count; i++)
                p2hand.Enqueue(input[i]);
        }

        static void Main(string[] args)
        {
            Queue<int> p1Hand, p2Hand;
            ReadLines(out p1Hand, out p2Hand);

            while (p1Hand.Count > 0 && p2Hand.Count > 0)
                MakeMove(p1Hand, p2Hand);

            int score;
            if (p1Hand.Count > 0)
                score = CountScore(p1Hand);
            else
                score = CountScore(p2Hand);

            Console.WriteLine($"{score}");
        }
    }
}
