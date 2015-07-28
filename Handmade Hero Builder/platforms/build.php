<?php 

function writeLn($str)
{
  echo $str."\r\n";
}

error_reporting(E_ALL); set_time_limit(0);

writeLn('   ___ ___                     ___ _____               ___         ___ ___                         ');
writeLn('  /   |   \_____    ____    __| _//     \ _____     __| _/____    /   |   \   ___________  ____    ');
writeLn(' /         \__  \  /    \  / __ |/  \ /  \\__  \   / __ |/ __ \  /         \_/ __ \_  __ \/  _ \   ');
writeLn(' \    Y    // __ \|   |  \/ /_/ /    Y    \/ __ \_/ /_/ \  ___/  \    Y    /\  ___/|  | \(   _  )  ');
writeLn('  \___|_  /(____  /___|  /\____ \____|__  (____  /\____ |\___  >  \___|_  /  \___  >__|   \____/   ');
writeLn('        \/      \/     \/      \/       \/     \/      \/    \/         \/       \/                ');
writeLn('__________       __ __        ___             ');
writeLn('\______   \__ __|__|  |    __| _/___________  ');
writeLn(' |    |  _/  |  \  |  |   / __ |/ __ \_  __ \ ');
writeLn(' |    |   \  |  /  |  |__/ /_/ \  ___/|  | \/ ');
writeLn(' |______  /____/|__|____/\____ |\___  >__|    ');
writeLn('        \/                    \/    \/        ');
writeLn(' The complete build solution for the current platforms:');
writeLn(' ');
writeLn(' * Windows Visual Studio 2015');
writeLn(' * Linux GNU Compiler');
writeLn(' * Linux Winelib');
writeLn(' * OS X port');
writeLn(' * Swift Cocoa Platform');
writeLn(' * X protocol C-language binding platform');
writeLn(' * Android NDK platform');
writeLn(' * iOS port');
writeLn(' * Qt platform');

die(0);
?>