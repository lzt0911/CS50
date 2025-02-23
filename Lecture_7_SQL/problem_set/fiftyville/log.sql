-- Keep a log of any SQL queries you execute as you solve the mystery.
-- get crime_scene_reports on 2023.7.28 in Humphrey Street
-- result:
-- 10:15am, the Humphrey Street bakery, three witness, id = 295
SELECT id, description FROM crime_scene_reports WHERE
    year = 2023 AND
    month = 7 AND
    day = 28 AND
    street = 'Humphrey Street';

-- get interview message
-- result:
-- within 10 minutes(before10:25am), thief get into a car and drive away
-- early in the morning, thief in Leggett Street ATM withdrawing some money
--  As the thief was leaving the bakery, called someone less than 1 minute take the earliest flight out of Fiftyville tomorrow.
SELECT id, transcript FROM interviews WHERE
    year = 2023 AND
    month = 7 AND
    day = 28;

-- get atm message
-- result:
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
SELECT * FROM atm_transactions WHERE
    year = 2023 AND
    month = 7 AND
    day = 28 AND
    atm_location = 'Leggett Street' AND
    transaction_type = 'withdraw';

-- get phone_calls message
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2023 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2023 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
-- | 234 | (609) 555-5876 | (389) 555-5198 | 2023 | 7     | 28  | 60       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2023 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2023 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2023 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2023 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2023 | 7     | 28  | 54       |
-- +-----+----------------+----------------+------+-------+-----+----------+
SELECT * from phone_calls WHERE
    year = 2023 AND
    month = 7 AND
    day = 28 AND
    duration <= 60;

-- get bakery_security_logs
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
-- +-----+------+-------+-----+------+--------+----------+---------------+
SELECT * FROM bakery_security_logs WHERE
    year = 2023 AND
    month = 7 AND
    day = 28 AND
    hour = 10 AND
    minute < 25 AND
    activity = 'exit';


-- get message from flights
-- result:
-- the earlist flight is id = 36, destination_airport_id = 4(New York City)
SELECT * FROM flights WHERE origin_airport_id is
    (SELECT id FROM airports WHERE city = 'Fiftyville') AND
    year = 2023 AND
    month = 7 AND
    day = 29;
SELECT * FROM airports WHERE id = 4;

-- put all messages together
-- result: Bruce
SELECT * FROM people WHERE
    (phone_number in (SELECT caller from phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration <= 60)) AND
    (passport_number in (SELECT passport_number FROM passengers WHERE flight_id = 36)) AND
    (license_plate in (SELECT license_plate FROM bakery_security_logs WHERE
    year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit')) AND
    (id in (SELECT person_id FROM bank_accounts WHERE
    account_number in (SELECT account_number FROM atm_transactions WHERE
    year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')));

-- get accomplice
SELECT * FROM people WHERE phone_number is
    (SELECT receiver FROM phone_calls WHERE caller is
    (SELECT phone_number FROM people WHERE id = 686048) AND year = 2023 AND month = 7 AND day = 28 AND duration <= 60);
