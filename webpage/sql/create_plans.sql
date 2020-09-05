create table plans (
    plan_id varchar(100) primary key,
    name varchar(100) NOT null,
    description varchar(200),
    status varchar(50)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;