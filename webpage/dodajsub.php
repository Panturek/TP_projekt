<?php

	session_start();
	
	$front = $_POST['front'];
	$back = $_POST['back'];
	
	require_once "config.php";

	$owner = $_SESSION['id'];
	
	if($conn->connect_errno!=0){
		echo "Error!: ".$conn->connect_errno." Opis: ".$conn->connect_error;
	}
	else{
		if($conn->query("INSERT INTO fiszki(ownerId, front, back) 
			VALUES ('$owner','$front', '$back')"))
		{
			$_SESSION['dodano'] = true;
			
		}
		else
		{
			$_SESSION['dodano'] = false;
		}
	}

	$conn->close();
	
	header("Location: dodaj.php");
	exit();
	
?>