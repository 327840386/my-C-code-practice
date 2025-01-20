
import random

QUESTIONS = ["Which line(s) of code represents the base case in your recursion, and what values will the variables involved have when the base case is hit? Explain the base case.",
             "The big O for mergesort is O(n log n). Which lines of code contribute to the O(n)? Explain how they contribute to O(n)",
             "Why do we pass temp[] as an argument? What would we need to do if we did not pass temp[] as an argument?",
             "Which dataset out of datasets 1-6 in your code will require mergesort to make the most comparisons, and why?",
             "The big O of mergesort is O(n log n). Which lines of code specifically account for the log n portion of its time complexity?",
             "When dataset 6 is sorted, what are the values of l and r in the base case, and how many times is the merge function called? Explain how you know.",
             ]


def main():
    choice = random.choice(QUESTIONS)
    print(choice)


if __name__ == "__main__":
    main()