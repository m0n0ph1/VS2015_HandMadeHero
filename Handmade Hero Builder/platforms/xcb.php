<?php 

function writeLn($str)
{
  echo $str."\r\n";
}

error_reporting(E_ALL); set_time_limit(0);

writeLn('Build For XCB');

die(0);
?>