import csv
import sys
from sys import argv


def main():

    # Check for command-line usage
    if not len(argv) == 3:
        print("Usage: python dna.py [CSV file] [DNA sequences text] ")

    # Read database file into a variable
    db = []
    with open(argv[1]) as f:
        reader = csv.DictReader(f)
        for row in reader:
            db.append(row)

    # Read DNA sequence file into a variable
    sequence = None
    with open(argv[2]) as f:
        sequence = f.read()

    # Find longest match of each STR in DNA sequence
    length = {}
    for key in list(db[0].keys())[1:]:
        length[key] = longest_match(sequence, key)

    # Check database for matching profiles
    for row in db:
        for key in list(db[0].keys())[1:]:
            if not int(row[key]) == int(length[key]):
                break
        else:
            print(list(row.values())[0])
            break
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
