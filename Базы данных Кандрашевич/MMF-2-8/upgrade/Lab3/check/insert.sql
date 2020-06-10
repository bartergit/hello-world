INSERT INTO Championship(NAME, CHAMP_YEAR)
SELECT DISTINCT League, Championship FROM DATA_TABLE;


INSERT INTO Stadium(NAME, Location, Occupancy)
SELECT DISTINCT Venue, Location, Capacity FROM DATA_TABLE;


INSERT INTO TEAM(NAME, Year_of_foundation)
SELECT DISTINCT Team_1, Founded_Team_1 FROM DATA_TABLE
UNION 
SELECT DISTINCT Team_2, Founded_Team_2 FROM DATA_TABLE;


INSERT INTO Coach(NAME, Team_ID)
SELECT DISTINCT Trainer_Team_1, TEAM1.ID FROM DATA_TABLE
INNER JOIN TEAM TEAM1 ON DATA_TABLE.Team_1 = TEAM1.NAME
UNION
SELECT DISTINCT Trainer_Team_2, TEAM2.ID FROM DATA_TABLE
INNER JOIN TEAM TEAM2 ON DATA_TABLE.Team_2 = TEAM2.NAME;


INSERT INTO SPIEL(Stadium_id, Team_winner_id, Team_loser_id, Spiel_date, Tickets_sold, Championship_id, Avg_price)
SELECT DISTINCT Stadium.id, Team1.id, Team2.id, Event_date, Tickets_sold, Championship.id, Avg_price FROM DATA_TABLE
INNER JOIN Stadium ON DATA_TABLE.Venue = Stadium.NAME
INNER JOIN TEAM Team1 ON DATA_TABLE.Team_1 = Team1.NAME
INNER JOIN TEAM Team2 ON DATA_TABLE.Team_2 = Team2.NAME
INNER JOIN Championship ON DATA_TABLE.League = Championship.NAME;


INSERT INTO Team_statistics(Team_ID)
SELECT DISTINCT TEAM.ID FROM TEAM;


INSERT INTO Player(NAME, POSITION, Team_ID)
SELECT DISTINCT Player_Last_Name, POSITION, TEAM.ID FROM DATA_TABLE
INNER JOIN TEAM ON DATA_TABLE.Player_Team = TEAM.NAME;


INSERT INTO Player_statistics(Player_ID)
SELECT DISTINCT Player.ID FROM Player;

INSERT INTO Event(Event_type, Spiel_id, Player_id, Event_Time)
SELECT DISTINCT Event, Spiel.id, Player.ID, Event_Time FROM DATA_TABLE
INNER JOIN Spiel ON DATA_TABLE.Event_date = Spiel.Spiel_date
INNER JOIN Player ON DATA_TABLE.Player_Last_Name = Player.NAME;
