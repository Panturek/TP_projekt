<?php
	session_start();
	
	if(!isset($_SESSION['delete'])){$_SESSION['delete'] = 0;}
	
	$id=$_SESSION['id'];
	$aus=false;
	
	require_once "config.php";

	if($conn->connect_errno!=0){
		echo "Error!: ".$conn->connect_errno." Opis: ".$conn->connect_error;
	}
	
			
	else{
			
		
		if(!$aus){
			if($rezultat=@$conn->query(
			sprintf("SELECT COUNT(*) AS \"num\" FROM fiszki WHERE ownerId='$id'"))){
				$wiersz=$rezultat->fetch_assoc();
				if($wiersz['num'] > 1){
					$aus = true;
				}
			}
		}
		
		do
			if($rezultat=@$conn->query(
			sprintf("SELECT * FROM fiszki WHERE ownerId=".$id." ORDER BY RAND() LIMIT 1"))){

				$wiersz=$rezultat->fetch_assoc();
			}
		while($_SESSION['delete']==$wiersz['id'] && $aus );
				
		$_SESSION['delete'] = $wiersz['id'];
			
		echo $wiersz['front'].'@'.$wiersz['back'];
	}
	
	$conn->close();
?>