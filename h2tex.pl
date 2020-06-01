#!/usr/bin/perl
use strict;
use warnings;
use v5.10;
use Data::Dumper;

my %entries;

foreach my $h (glob '*.h') {
	my @namespace = ();
	our $namespace = '';
	open (my $f, '<', $h)  or die "$h: $!\n";
	foreach my $line (<$f>) {
		sub add_entry {
			my ($pre, $id, $post) = @_;
			exists $entries{$id}  and die "duplicate key at \"$h\":\n$line\n";
			$entries{$id} = { id => $id, pre => $pre, post => $post, namespace => $namespace };
		}
		if ($line =~ /^\s*namespace\s+(\w+)\b/) {
			push @namespace, $1;
			$namespace = join('::', @namespace);
		}
		elsif ($namespace and $line =~ /^\s*(.*?\ )(\w+)(\s*\(.*\);)/) {
			my ($pre, $method, $post) = ($1, $2, $3);
			add_entry ($pre, $method, $post);
		}
		elsif ($namespace and $line =~ /^\s*struct\s+(\w+)\s*{?$/) {
			my ($struct) = ($1);
			#add_entry ('struct ', $struct, '');
		}
	}
	close $f;
}

foreach my $m (sort keys %entries) {
	my $command = $entries{$m}->{id};
	$command =~ s/^(.)/uc($1)/eg;
	$command =~ s/_(.)/uc($1)/eg;

	my ($pre, $id, $post) =
		map { s/([&_])/\\$1/g; $_ }
		map { $entries{$m}->{$_} }
		qw/pre id post/;

	my $ns = $entries{$m}->{namespace};
	say '\\DefineAPI'
		.'{'.$command.'}'
		.'{'.$pre.(($ns =~ /native/) ? $ns.'::' : '').'}'
		.'{'.$id.'}'
		.'{'.$post.'}'
	;
}
