<?php

$config = parse_ini_file('./ini/rest.ini');

$host = $config['host'];
$db_user = $config['db_user'];
$db_password = $config['db_password'];
$db_name = $config['db_name'];

$conn=@new mysqli($host, $db_user, $db_password, $db_name);
if(!$conn){
    die(mysqli_connection_error());
}
mysqli_select_db($conn, $config['db_name']);

?>