create table executives (
	id int PRIMARY KEY AUTO_INCREMENT,
    plan_id text not null,
    user_id int NOT null,
    assignment_date datetime not null,
    discharge_date datetime not null
) ENGINE=InnoDB DEFAULT CHARSET=utf8;