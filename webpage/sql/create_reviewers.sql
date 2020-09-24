create table reviewers (
	id int PRIMARY KEY AUTO_INCREMENT,
    plan_id text not null,
    user_id int not null,
    assignment_date datetime not null,
    discharge_date datetime
) ENGINE=InnoDB DEFAULT CHARSET=utf8;