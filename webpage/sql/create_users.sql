CREATE TABLE `users` (
  `id` int(11) not null,
  `user` text COLLATE utf8_polish_ci not null,
  `pass` text COLLATE utf8_polish_ci not null,
  `email` text COLLATE utf8_polish_ci not null,
  `join_date` datetime not null,
  `aus` tinyint(1) not null
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;
