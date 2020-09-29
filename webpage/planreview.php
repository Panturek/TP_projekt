<?php

if($_SERVER['REQUEST_METHOD'] == "POST"){
    $plan_id = "";
    $user_id = ""; 
    $entityBody = file_get_contents('php://input');
    $json = json_decode($entityBody, true);
    if (json_last_error() == JSON_ERROR_NONE) {
        $plan_id = $json['plan_id'];
        $user_id = $json['user_id'];
    }
    else{
        echo "plan file format corrupted";
    }

    include_once( 'config.php');
    $select_reviewers = "select * from $db_name.reviewers
                        where user_id like ".$user_id.
                        " and plan_id like ".$plan_id;

    $select_executed = "select executives.user_id, users.user
                        from $db_name.executives, $db_name.users
                        where executives.plan_id like ".$plan_id."
                        and executives.user_id like users.id";

    $get_reviewers = mysqli_query($conn, $select_reviewers);
    $get_executives = mysqli_query($conn, $select_executed);

    if($get_reviewers){
        $isReviewer = mysqli_fetch_all($get_reviewers);
    }
    if($get_executives){
        $executives = mysqli_fetch_all($get_executives);
    }
    

    if(isset($isReviewer) && $isReviewer!=false ){
        if(isset($executives)){
            array_push( $executives, $plan_id );
            echo json_encode($executives);
        }
        else{
            echo '{
                "status": "'.mysqli_error($conn).'" 
            }';
        }
    }
    else{
        echo '{
            "status": "access denied"
        }';
    }
    @mysqli_close($conn);
}
?>
