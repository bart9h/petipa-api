#!/usr/bin/perl
use strict;
use warnings;
use v5.10;
use Data::Dumper;

my %methods;

foreach my $h (glob '*.h') {
	my @namespace = ();
	my $namespace;
	open (my $f, '<', $h)  or die "$h: $!\n";
	foreach my $line (<$f>) {
		if ($line =~ /^\s*namespace\s+(\w+)\b/) {
			push @namespace, $1;
			$namespace = join('::', @namespace);
		}
		elsif ($namespace and $line =~ /^\s*(.*?\ )(\w+)(\s*\(.*\);)/) {
			my ($pre, $method, $post) = ($1, $2, $3);
			exists $methods{$method}  and die "duplicate method at \"$h\":\n$line\n";
			$methods{$method} = { pre => $pre, namespace => $namespace, method => $method, post => $post };
		}
	}
	close $f;
}

foreach my $m (sort keys %methods) {
	my $command = $methods{$m}->{method};
	$command =~ s/^(.)/uc($1)/eg;
	$command =~ s/_(.)/uc($1)/eg;

	my ($pre, $method, $post) =
		map { s/([&_])/\\$1/g; $_ }
		map { $methods{$m}->{$_} }
		qw/pre method post/;

	say '\\DefineAPI'
		.'{'.$command.'}'
		.'{'.$pre.$methods{$m}->{namespace}.'}'
		.'{'.$method.'}'
		.'{'.$post.'}'
	;
}
