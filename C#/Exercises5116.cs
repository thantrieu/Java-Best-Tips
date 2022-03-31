using System;

namespace AdsAndSupport
{
    class Exercises5116
    {
        static void Main()
        {
            int t = int.Parse(Console.ReadLine());
            for (int test = 1; test <= t; test++)
            {
                var elements = Console.ReadLine().Split(' ');
                var n = elements.Length;
                var arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    arr[i] = int.Parse(elements[i]);
                }
                Console.WriteLine($"Test {test}: ");
                var startPos = 0;
                var length = -1;
                MaxIncrement(arr, ref startPos, ref length);
                ShowElements(arr, startPos, length);
            }
        }

        // phương thức tìm vị trí bắt đầu và số lượng phần tử của dãy tăng dài nhất trong mảng
        static void MaxIncrement(int[] arr, ref int startPos, ref int length)
        {
            // TH1: cả mảng là 1 dãy tăng duy nhất
            // TH2: mảng có nhiều dãy tăng với độ dài khác nhau, chỉ có 1 dãy có độ dài max
            // TH3: mảng có nhiều dãy tăng với cùng độ dài max
            int countElement = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                countElement++;
                if(i + 1 < arr.Length && arr[i + 1] < arr[i])
                {
                    if(countElement > length)
                    {
                        length = countElement;
                        startPos = i + 1 - length;
                    }
                    countElement = 0;
                }
            }
            length = (length == -1) ? arr.Length : length;
        }

        // in ra kết quả
        static void ShowElements(int[] arr, int startPos, int numOfElement)
        {
            for (int i = startPos; i < startPos + numOfElement; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine();
        }
    }
}
