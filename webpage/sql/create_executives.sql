create table executives (
	id int primary key AUTO_INCREMENT,
    plan_id text not null,
    user_id int not null,
    assignment_date datetime,
    discharge_date datetime 
) ENGINE=InnoDB DEFAULT CHARSET=utf8;