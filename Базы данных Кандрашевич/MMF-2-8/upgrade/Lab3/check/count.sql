declare
    num NUMBER;    
begin
	select count(id) into num from Team;
	dbms_output.put_line('Team, number of rows: ' || num);
	select count(id) into num from Player;
	dbms_output.put_line('Player, number of rows: ' || num);
	select count(id) into num from Stadium;
	dbms_output.put_line('Stadium, number of rows: ' || num);
	select count(id) into num from Spiel;
	dbms_output.put_line('Spiel, number of rows: ' || num);
	select count(id) into num from Championship;
	dbms_output.put_line('Championship, number of rows: ' || num);
	select count(id) into num from Player_statistics;
	dbms_output.put_line('Player_statistics, number of rows: ' || num);
	select count(id) into num from Coach;
	dbms_output.put_line('Coach, number of rows: ' || num);
	select count(id) into num from Event;
	dbms_output.put_line('Event, number of rows: ' || num);
	select count(id) into num from Team_statistics;
	dbms_output.put_line('Team_statistics, number of rows: ' || num);
end;
/