<?php

	session_start();
	
	require_once "connect.php";
	
	$bye = $_SESSION['delete'];
	
	$polaczenie=@new mysqli($host, $db_user, $db_password, $db_name);
	
	if($polaczenie->connect_errno!=0){
		echo "Error!: ".$polaczenie->connect_errno." Opis: ".$polaczenie->connect_error;
	}
	else{
		if($polaczenie->query("DELETE FROM fiszki WHERE fiszki.id = '$bye';"))
		{
			
		}
		else
		{
			
		}
	}
	
	$polaczenie->close();
	
	header("Location: fiszki.php");
	exit();
	
?>