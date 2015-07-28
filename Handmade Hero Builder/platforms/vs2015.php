<?php 

function writeLn($str)
{
  echo $str."\r\n";
}

function copyFile($source, $dest)
{
  writeLn('......copying - '.$source.' => '.$dest);
  if(!@copy($source, $dest))fatalError('Failed to copy file.');
}

error_reporting(E_ALL); set_time_limit(0);

writeLn('Build For Visual Studio 2015');
exec('cd');
copyFile("test_src/win32handmade.cpp","test_binaries/win32handmade.exe");
exec('"cd "C:\Users\protoplasm\Documents\GitHub\VS2015_HandMadeHero\Handmade Hero Builder\MinGW\bin\"');
exec('cd');
exec('"c++.exe" "C:\Users\protoplasm\Documents\GitHub\VS2015_HandMadeHero\Handmade Hero Builder\test_src\win32handmade.cpp" -o "C:\Users\protoplasm\Documents\GitHub\VS2015_HandMadeHero\Handmade Hero Builder\test_src\handy.exe"');

die(0);
?>