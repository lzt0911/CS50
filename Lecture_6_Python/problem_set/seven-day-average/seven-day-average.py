import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    previous_cases = {}  # 记录每个state当前的cases
    cases = {}
    for row in reader:
        if row["state"] in previous_cases:
            if len(cases[row["state"]]) == 14:
                cases[row["state"]].pop(0)
            cases[row["state"]].append(int(row["cases"]) - int(previous_cases[row["state"]]))
        else:
            cases[row["state"]] = list()
        previous_cases[row["state"]] = row["cases"]

    return cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        old_average = sum(new_cases[state][:7]) / 7
        new_average = sum(new_cases[state][7:]) / 7

        try:
            if new_average > old_average:
                print(f"{state} had a 7-day average of {new_average:.2f} and an increase of {((new_average - old_average) / old_average * 100):.2f}%")
            else:
                print(f"{state} had a 7-day average of {new_average:.2f} and a decrease of {((old_average - new_average) / old_average * 100):.2f}%")
        except ZeroDivisionError:
            print("divided by zero")


main()
