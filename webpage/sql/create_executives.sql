create table executives (
	id int PRIMARY KEY AUTO_INCREMENT,
    plan_id text not null,
    user_id int NOT null,
    assignment_date datetime,
    discharge_date datetime 
) ENGINE=InnoDB DEFAULT CHARSET=utf8;