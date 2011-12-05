use strict;
use warnings;
use LWP::UserAgent;
use HTML::TreeBuilder;

my $url = 'http://ameblo.jp/staff/theme-10000150585.html';
my $user_agent = "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/4.0)";

my $ua = LWP::UserAgent->new('agent' => $user_agent);
my $res = $ua->get($url);
my $content = $res->content;

my $tree = HTML::TreeBuilder->new;
$tree->parse($content);

my $elm  = $tree->look_down('class', 'title');
my  @list =  $elm->find('h3');
for my $h3 (@list) {
    print $h3->as_text."\n"
} 

