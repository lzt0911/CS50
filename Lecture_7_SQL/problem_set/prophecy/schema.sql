
CREATE TABLE students_new (
    id INTEGER,
    name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER,
    name TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE assignment (
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY(student_id) REFERENCES students_new(id),
    FOREIGN KEY(house_id) REFERENCES houses(id)
);
