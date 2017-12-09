/* temporary placeholder
*/
DROP TABLE IF EXISTS student_music;
DROP TABLE IF EXISTS student_instrument;
DROP TABLE IF EXISTS instruments;
DROP TABLE IF EXISTS music;
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS bands;

CREATE TABLE bands (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  name VARCHAR(26) NOT NULL, 
  director_fname VARCHAR(26) NOT NULL, 
  director_lname VARCHAR(26) NOT NULL, 
  PRIMARY KEY (id),
  UNIQUE (name)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE students (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  fname VARCHAR(26) NOT NULL, 
  lname VARCHAR(26) NOT NULL, 
  grade INT UNSIGNED NOT NULL,
  bid INT UNSIGNED NOT NULL,
  FOREIGN KEY(bid) REFERENCES bands (id),
  PRIMARY KEY (id),
  UNIQUE (fname, lname)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE instruments (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  type VARCHAR(255) NOT NULL, 
  manufacturer VARCHAR(255) NOT NULL, 
  serial_num VARCHAR(48),
  needs_repair BOOL NOT NULL,
  last_repair_date DATE,
  PRIMARY KEY (id),
  UNIQUE (serial_num,manufacturer)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE music (
  id INT UNSIGNED PRIMARY KEY NOT NULL AUTO_INCREMENT,
  title VARCHAR(255) NOT NULL, 
  composer VARCHAR(255) NOT NULL, 
  temp_bpm INT UNSIGNED, 
  difficulty INT UNSIGNED,
  length TIME
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE student_instrument (
  id INT UNSIGNED PRIMARY KEY NOT NULL AUTO_INCREMENT,
  sid INT UNSIGNED NOT NULL,
  iid INT UNSIGNED NOT NULL,
  FOREIGN KEY(sid) REFERENCES students (id),
  FOREIGN KEY(iid) REFERENCES instruments (id),
  UNIQUE (sid),
  UNIQUE (iid)
) ENGINE=InnoDB;

/*
CREATE TABLE practice_records 
(
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  sid INT UNSIGNED NOT NULL,
  date DATE,
  minutes INT UNSIGNED NOT NULL,
  FOREIGN KEY (sid) REFERENCES students (id),
  PRIMARY KEY (id)
) ENGINE=InnoDB;
*/

CREATE TABLE student_music (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  sid INT UNSIGNED NOT NULL,
  mid INT UNSIGNED NOT NULL,
  note VARCHAR(256), 
  FOREIGN KEY(sid) REFERENCES students (id),
  FOREIGN KEY(mid) REFERENCES music (id),
  PRIMARY KEY (id)
) ENGINE=InnoDB;

CREATE TABLE band_music (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  bid INT UNSIGNED NOT NULL,
  mid INT UNSIGNED NOT NULL,
  FOREIGN KEY(bid) REFERENCES bands (id),
  FOREIGN KEY(mid) REFERENCES music (id),
  PRIMARY KEY (id)
) ENGINE=InnoDB;
