DEFINE DATA_TBS_NAME = &&1
-- ---
-- Table 'Player'
-- Информацию о игроках (персоальная)
-- ---

CREATE TABLE Team (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Name VARCHAR(50),
  Year_of_foundation INTEGER,
  Rating DECIMAL(4,2),
  PRIMARY KEY (id)
)
TABLESPACE &&DATA_TBS_NAME;


CREATE TABLE Player (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Name VARCHAR(50),
  Position VARCHAR(50),
  Team_id INTEGER,
  Age INTEGER,
  PRIMARY KEY (id),
  FOREIGN KEY (Team_id) REFERENCES Team(id)
) 
TABLESPACE &&DATA_TBS_NAME;


-- ---
-- Table 'Stadium'
-- Стадионы
-- ---

    
CREATE TABLE Stadium (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Occupancy INTEGER,
  Name VARCHAR(50),
  Location VARCHAR(50),
  PRIMARY KEY (id)
)
TABLESPACE &&DATA_TBS_NAME;


CREATE TABLE Championship (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Name VARCHAR(50),
  champ_year INTEGER,
  PRIMARY KEY (id)
)
TABLESPACE &&DATA_TBS_NAME;



-- ---
-- Table 'Spiel'
-- Информация о матчах
-- ---
    
CREATE TABLE Spiel (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Stadium_id INTEGER,
  Team_winner_id INTEGER,
  Team_loser_id INTEGER,
  Spiel_date DATE,
  Tickets_sold INTEGER,
  Championship_id INTEGER,
  Avg_price INTEGER,
  PRIMARY KEY (id),
  FOREIGN KEY (Stadium_id) REFERENCES Stadium(id),
 FOREIGN KEY (Team_winner_id) REFERENCES  Team(id),
 FOREIGN KEY (Championship_id) REFERENCES  Championship(id),
 FOREIGN KEY (Team_loser_id) REFERENCES  Team(id)
)
TABLESPACE &&DATA_TBS_NAME;


CREATE TABLE Event (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Event_type VARCHAR(50),
  Spiel_id INTEGER,
  Player_id INTEGER,
  Event_time INTEGER,
  PRIMARY KEY (id),
  FOREIGN KEY (Player_id) REFERENCES Player(id),
  FOREIGN KEY (Spiel_id) REFERENCES Spiel(id)
)
TABLESPACE &&DATA_TBS_NAME;


-- ---
-- Table 'Сhampionship'
-- Информация о чемпионатах
-- ---
    


-- ---
-- Table 'Player_statistics'
-- Статистика по игрокам
    
CREATE TABLE Player_statistics (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Player_id INTEGER,
  Spiel_counter INTEGER,
  Goal_counter INTEGER,
  Penalty_counter INTEGER,
  Assists_counter INTEGER,
  Removal_counter INTEGER,
  PRIMARY KEY (id),
  FOREIGN KEY (Player_id) REFERENCES Player(id)
)
TABLESPACE &&DATA_TBS_NAME;



-- ---
-- Table 'Coaches'
-- Тренеры
-- ---

    
CREATE TABLE Coach (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Team_id INTEGER,
  Name VARCHAR(50),
  Age INTEGER,
  PRIMARY KEY (id),
  FOREIGN KEY (Team_id) REFERENCES Team(id)
)
TABLESPACE &&DATA_TBS_NAME;

-- ---
-- Table 'Team_statistics'
-- Статистика по командам
-- ---

    
CREATE TABLE Team_statistics (
  id NUMBER GENERATED ALWAYS AS IDENTITY NOT NULL,
  Team_id INTEGER,
  Goal_counter INTEGER,
  Avg_hit_counter DECIMAL(3,1),
  Red_cards INTEGER,
  Yellow_cards INTEGER,
  PRIMARY KEY (id),
  FOREIGN KEY (Team_id) REFERENCES Team(id)
)
TABLESPACE &&DATA_TBS_NAME;

UNDEFINE DATA_TBS_NAME;
