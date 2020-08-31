<?php

	session_start();
	
	require_once "config.php";
	
    $bye = $_SESSION['delete'];
    
	if($conn->connect_errno!=0){
		echo "Error!: ".$conn->connect_errno." Opis: ".$conn->connect_error;
	}
	else{
		if($conn->query("DELETE FROM fiszki WHERE fiszki.id = '$bye';"))
		{
			
		}
		else
		{
			
		}
	}
	
	$conn->close();
	
	header("Location: fiszki.php");
	exit();
	
?>