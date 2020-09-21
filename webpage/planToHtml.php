<?php

function getPlanMeta($json){
    $plan = json_decode($json, true);
    echo $plan['Meta']['Name'].'<br/>';
    echo $plan['Meta']['Description'].'<br/>';
}


function getPlanData($pathToPlan){
    $json = file_get_contents($pathToPlan);
    $plan = json_decode($json, true);
    getPlanMeta($json);
    echo ($plan['TasksOrdered'] ? "ordered" : 'unordered') .'<br/>';
    echo $plan['StatusDisplay'].'<br/>';
    echo implode($plan['StatesAllowed']).'<br/>';
    
    foreach ($plan['Tasks'] as $key1 => $value) {
        echo $key1.' '.$value;
    }
}

?>