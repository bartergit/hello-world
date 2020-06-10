DEFINE VIEW_NAME = MMF_2_8_VIEW

-- DROP VIEW &&VIEW_NAME;

create view &&VIEW_NAME as 
select 
    Championship.champ_year Championship,
    Championship.Name League,
    Team_1.year_of_foundation Founded_Team_1,
    Coach_1.Name Trainer_Team_1,
    Team_2.year_of_foundation Founded_Team_2,
    Coach_2.Name Trainer_Team_2,
    Team_1.Name Team_1,
    Team_2.Name Team_2,
    Event.Event_type Event,
    Player.Name Player_Last_Name,
    Player_Team.Name Player_Team,
    Player.Position,
    Event.Event_time,
    Spiel.Spiel_date Event_date,
    Stadium.Location,
    Stadium.Name Venue,
    Stadium.Occupancy,
    Spiel.Avg_price,
    Spiel.tickets_sold
from
    Championship
inner join Spiel
    on Spiel.Championship_id = Championship.id
inner join Team Team_1
    on Team_1.id = Spiel.Team_winner_id
INNER JOIN TEAM Team_2
    ON Team_2.id = Spiel.Team_loser_id
inner join Coach Coach_1
    on Coach_1.Team_id = Team_1.id
INNER JOIN Coach Coach_2
    ON Coach_2.Team_id = Team_2.id
inner join Stadium
    on Stadium.id = Spiel.Stadium_id
inner join Event 
    on Event.Spiel_id = Spiel.id
inner join Player
    on Event.Player_id = Player.id
inner join Team Player_Team
    on Player_Team.id = Player.TEAM_id
group by 
    Championship.champ_year,
    Championship.Name,
    Team_1.year_of_foundation ,
    Team_2.year_of_foundation ,
    Coach_1.Name ,
    Coach_2.Name ,
    Team_1.Name ,
    Team_2.Name ,
    Event.Event_type,
    Player.Name ,
    Player_Team.Name ,
    Player.Position,
    Event.Event_time,
    Spiel.Spiel_date,
    Stadium.Location,
    Stadium.Name ,
    Stadium.Occupancy,
    Spiel.Avg_price,
    Spiel.tickets_sold
order by Spiel.Spiel_date;

-- select * from data_table
-- minus
-- select * from MMF_2_8_VIEW;