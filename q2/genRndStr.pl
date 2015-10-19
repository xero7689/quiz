my @chars = ("A".."Z", "a".."z");
my $string;
$string .= $chars[rand @chars] for 1..$ARGV[0];
print join('',sort(split(//,$string))) ."\n";
