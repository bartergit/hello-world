connect MMF_2_8/oracle 


CREATE TABLE DATA_TABLE (
    Championship INTEGER,
    League VARCHAR2(300),
    Founded_Team_1 INTEGER,
    Trainer_Team_1 VARCHAR2(300),
    Founded_Team_2 INTEGER,
    Trainer_Team_2 VARCHAR2(300),
    Team_1 VARCHAR2(300),
    Team_2 VARCHAR2(300),
    Event VARCHAR2(300),
    Player_Last_Name VARCHAR2(300),
    Player_Team VARCHAR2(300),
    Position VARCHAR2(300),
    Event_Time INTEGER,
    Event_Date DATE,
    Location VARCHAR2(300),
    Venue VARCHAR2(300),
    Capacity INTEGER,
    Avg_price INTEGER,
    tickets_sold INTEGER
)
TABLESPACE MMF_2_8_DATA;

alter session set nls_date_format = 'dd-mm-yyyy';

-- alter session set nls_language = RUSSIAN;

INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Goal','?ó¨ Š£÷','????','?  ª şù£Š',12,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Goal','?ò ñ½€£÷','????','?¡ó¯ ù£ò­£Œ',17,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Goal','?½õ Š÷£Œ','????','?¡ó¯ ù£ò­£Œ',70,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Goal','? ª£ÿ­','?½ ­','?¡ó¯ ù£ò­£Œ',31,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Yellow card','?ó¨ Š£÷','????','?  ª şù£Š',22,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Yellow card','? ¨½£­','?½ ­','?¡ó¯ ù£ò­£Œ',23,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Yellow card','?¡€ ü','?½ ­','?  ª şù£Š',64,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?£ğ£ ?½òğ¡€£÷',1964,'?¡ğü ?¡€ ½€£÷','????','?½ ­','Yellow card','?½øŒ¡','?½ ­','? ù£ò­£Œ',72,'03-05-2020','Borisov','?¡ğ£ñ¡€-?ğ½­ ',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Goal','? ª£ÿ­','?½ ­','?¡ó¯ ù£ò­£Œ',68,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Goal','? ª£ÿ­','?½ ­','?¡ó¯ ù£ò­£Œ',91,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Goal','? ñ£ü½€','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',4,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Goal','?ğ½÷£õ¡','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',15,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Goal','?½ªüŒ¡','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',55,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Goal','?­ªğ¡­£Œ','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',90,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Yellow card','?½øŒ¡','?½ ­','? ù£ò­£Œ',68,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Yellow card','?½÷££­','?½ ­','?¡ó¯ ù£ò­£Œ',87,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Yellow card','? Šªó÷£Œ','?óõ ?ğ½ñò','? ù£ò­£Œ',35,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Yellow card','? ñ£ü½€','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',51,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Yellow card','? ñ£ü½€','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',86,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Yellow card','?­ªğ¡­£Œ','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',81,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?¡ğü ?¡€ ½€£÷',2016,'?½Œñ ­ªğ ?½ª­½€','?½ ­','?óõ ?ğ½ñò','Red card','? ñ£ü½€','?óõ ?ğ½ñò','?¡ó¯ ù£ò­£Œ',82,'09-05-2020','Grodno','??? ?½ ­',8479,16,5460);