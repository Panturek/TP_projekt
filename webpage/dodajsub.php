<?php

	session_start();
	
	$front = $_POST['front'];
	$back = $_POST['back'];
	
	require_once "connect.php";

	$polaczenie=@new mysqli($host, $db_user, $db_password, $db_name);

	$owner = $_SESSION['id'];
	
	if($polaczenie->connect_errno!=0){
		echo "Error!: ".$polaczenie->connect_errno." Opis: ".$polaczenie->connect_error;
	}
	else{
		if($polaczenie->query("INSERT INTO fiszki(ownerId, front, back) 
			VALUES ('$owner','$front', '$back')"))
		{
			$_SESSION['dodano'] = true;
			
		}
		else
		{
			$_SESSION['dodano'] = false;
		}
	}

	$polaczenie->close();
	
	header("Location: dodaj.php");
	exit();
	
?>