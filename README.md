This is an attempt to build solo for the ESP32 (later with authentication via BLE).

Status: component 'solo' compiles... (no functional tests possible so far)

# Building

Install the [ESP-IDF](https://github.com/espressif/esp-idf).

Clone the repository into a components subdirectory of your project using:
```
git clone --recurse-submodules https://github.com/martin-ger/solo
```

Use `idf.py build` to build the ESP32 binary.


# Documentation

Check out the [official solo documentation](https://docs.solokeys.io/solo/).

# Contributors ✨

Solo is an upgrade to [U2F Zero](https://github.com/conorpp/u2f-zero). It was born from Conor's passion for making secure hardware, and from our shared belief that security should be open to be trustworthy, in hardware like in software.

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!
The ultimate goal is to have a FIDO2 security key supporting USB, NFC, and BLE interfaces, that can run on a variety of MCUs.
Look at the issues to see what is currently being worked on. Feel free to add issues as well.

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore -->
<table>
  <tr>
    <td align="center"><a href="https://github.com/szszszsz"><img src="https://avatars0.githubusercontent.com/u/17005426?v=4" width="100px;" alt="Szczepan Zalega"/><br /><sub><b>Szczepan Zalega</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=szszszsz" title="Code">💻</a> <a href="https://github.com/solokeys/solo/commits?author=szszszsz" title="Documentation">📖</a> <a href="#ideas-szszszsz" title="Ideas, Planning, & Feedback">🤔</a></td>
    <td align="center"><a href="https://github.com/Wesseldr"><img src="https://avatars1.githubusercontent.com/u/4012809?v=4" width="100px;" alt="Wessel dR"/><br /><sub><b>Wessel dR</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=Wesseldr" title="Documentation">📖</a></td>
    <td align="center"><a href="https://www.imperialviolet.org"><img src="https://avatars3.githubusercontent.com/u/21203?v=4" width="100px;" alt="Adam Langley"/><br /><sub><b>Adam Langley</b></sub></a><br /><a href="https://github.com/solokeys/solo/issues?q=author%3Aagl" title="Bug reports">🐛</a> <a href="https://github.com/solokeys/solo/commits?author=agl" title="Code">💻</a></td>
    <td align="center"><a href="http://www.lotteam.com"><img src="https://avatars2.githubusercontent.com/u/807634?v=4" width="100px;" alt="Oleg Moiseenko"/><br /><sub><b>Oleg Moiseenko</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=merlokk" title="Code">💻</a></td>
    <td align="center"><a href="https://github.com/aseigler"><img src="https://avatars1.githubusercontent.com/u/6605560?v=4" width="100px;" alt="Alex Seigler"/><br /><sub><b>Alex Seigler</b></sub></a><br /><a href="https://github.com/solokeys/solo/issues?q=author%3Aaseigler" title="Bug reports">🐛</a></td>
    <td align="center"><a href="https://www.cotech.de/services/"><img src="https://avatars3.githubusercontent.com/u/321888?v=4" width="100px;" alt="Dominik Schürmann"/><br /><sub><b>Dominik Schürmann</b></sub></a><br /><a href="https://github.com/solokeys/solo/issues?q=author%3Adschuermann" title="Bug reports">🐛</a></td>
    <td align="center"><a href="https://github.com/ehershey"><img src="https://avatars0.githubusercontent.com/u/286008?v=4" width="100px;" alt="Ernie Hershey"/><br /><sub><b>Ernie Hershey</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=ehershey" title="Documentation">📖</a></td>
  </tr>
  <tr>
    <td align="center"><a href="https://github.com/YakBizzarro"><img src="https://avatars1.githubusercontent.com/u/767740?v=4" width="100px;" alt="Andrea Corna"/><br /><sub><b>Andrea Corna</b></sub></a><br /><a href="#infra-YakBizzarro" title="Infrastructure (Hosting, Build-Tools, etc)">🚇</a></td>
    <td align="center"><a href="https://place.org/~pj/"><img src="https://avatars3.githubusercontent.com/u/11100?v=4" width="100px;" alt="Paul Jimenez"/><br /><sub><b>Paul Jimenez</b></sub></a><br /><a href="#infra-pjz" title="Infrastructure (Hosting, Build-Tools, etc)">🚇</a> <a href="https://github.com/solokeys/solo/commits?author=pjz" title="Code">💻</a></td>
    <td align="center"><a href="https://github.com/yparitcher"><img src="https://avatars0.githubusercontent.com/u/38916402?v=4" width="100px;" alt="yparitcher"/><br /><sub><b>yparitcher</b></sub></a><br /><a href="#ideas-yparitcher" title="Ideas, Planning, & Feedback">🤔</a> <a href="#maintenance-yparitcher" title="Maintenance">🚧</a></td>
    <td align="center"><a href="https://github.com/StoyanDimitrov"><img src="https://avatars1.githubusercontent.com/u/10962709?v=4" width="100px;" alt="StoyanDimitrov"/><br /><sub><b>StoyanDimitrov</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=StoyanDimitrov" title="Documentation">📖</a></td>
    <td align="center"><a href="https://github.com/alphathegeek"><img src="https://avatars2.githubusercontent.com/u/51253712?v=4" width="100px;" alt="alphathegeek"/><br /><sub><b>alphathegeek</b></sub></a><br /><a href="#ideas-alphathegeek" title="Ideas, Planning, & Feedback">🤔</a></td>
    <td align="center"><a href="https://xakcop.com"><img src="https://avatars2.githubusercontent.com/u/271616?v=4" width="100px;" alt="Radoslav Gerganov"/><br /><sub><b>Radoslav Gerganov</b></sub></a><br /><a href="#ideas-rgerganov" title="Ideas, Planning, & Feedback">🤔</a> <a href="https://github.com/solokeys/solo/commits?author=rgerganov" title="Code">💻</a></td>
    <td align="center"><a href="http://13-37.org"><img src="https://avatars3.githubusercontent.com/u/10274356?v=4" width="100px;" alt="Manuel Domke"/><br /><sub><b>Manuel Domke</b></sub></a><br /><a href="#ideas-manuel-domke" title="Ideas, Planning, & Feedback">🤔</a> <a href="https://github.com/solokeys/solo/commits?author=manuel-domke" title="Code">💻</a> <a href="#business-manuel-domke" title="Business development">💼</a></td>
  </tr>
  <tr>
    <td align="center"><a href="http://1bitsquared.com"><img src="https://avatars3.githubusercontent.com/u/17334?v=4" width="100px;" alt="Piotr Esden-Tempski"/><br /><sub><b>Piotr Esden-Tempski</b></sub></a><br /><a href="#business-esden" title="Business development">💼</a></td>
    <td align="center"><a href="https://github.com/m3hm00d"><img src="https://avatars1.githubusercontent.com/u/42179593?v=4" width="100px;" alt="f.m3hm00d"/><br /><sub><b>f.m3hm00d</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=m3hm00d" title="Documentation">📖</a></td>
    <td align="center"><a href="http://blogs.gnome.org/hughsie/"><img src="https://avatars0.githubusercontent.com/u/151380?v=4" width="100px;" alt="Richard Hughes"/><br /><sub><b>Richard Hughes</b></sub></a><br /><a href="#ideas-hughsie" title="Ideas, Planning, & Feedback">🤔</a> <a href="https://github.com/solokeys/solo/commits?author=hughsie" title="Code">💻</a> <a href="#infra-hughsie" title="Infrastructure (Hosting, Build-Tools, etc)">🚇</a> <a href="#tool-hughsie" title="Tools">🔧</a></td>
    <td align="center"><a href="http://www.schulz.dk"><img src="https://avatars1.githubusercontent.com/u/1150049?v=4" width="100px;" alt="Kim Schulz"/><br /><sub><b>Kim Schulz</b></sub></a><br /><a href="#business-kimusan" title="Business development">💼</a> <a href="#ideas-kimusan" title="Ideas, Planning, & Feedback">🤔</a></td>
    <td align="center"><a href="https://github.com/oplik0"><img src="https://avatars2.githubusercontent.com/u/25460763?v=4" width="100px;" alt="Jakub"/><br /><sub><b>Jakub</b></sub></a><br /><a href="https://github.com/solokeys/solo/issues?q=author%3Aoplik0" title="Bug reports">🐛</a></td>
    <td align="center"><a href="https://github.com/jolo1581"><img src="https://avatars1.githubusercontent.com/u/53423977?v=4" width="100px;" alt="Jan A."/><br /><sub><b>Jan A.</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=jolo1581" title="Code">💻</a> <a href="https://github.com/solokeys/solo/commits?author=jolo1581" title="Documentation">📖</a></td>
    <td align="center"><a href="https://github.com/ccinelli"><img src="https://avatars0.githubusercontent.com/u/38021940?v=4" width="100px;" alt="ccinelli"/><br /><sub><b>ccinelli</b></sub></a><br /><a href="#infra-ccinelli" title="Infrastructure (Hosting, Build-Tools, etc)">🚇</a> <a href="https://github.com/solokeys/solo/commits?author=ccinelli" title="Tests">⚠️</a></td>
  </tr>
  <tr>
    <td align="center"><a href="https://www.nitrokey.com"><img src="https://avatars1.githubusercontent.com/u/9438831?v=4" width="100px;" alt="Nitrokey"/><br /><sub><b>Nitrokey</b></sub></a><br /><a href="https://github.com/solokeys/solo/commits?author=Nitrokey" title="Code">💻</a> <a href="https://github.com/solokeys/solo/commits?author=Nitrokey" title="Tests">⚠️</a> <a href="#ideas-Nitrokey" title="Ideas, Planning, & Feedback">🤔</a></td>
  </tr>
</table>

<!-- ALL-CONTRIBUTORS-LIST:END -->


# License

Solo is fully open source.

All software, unless otherwise noted, is dual licensed under Apache 2.0 and MIT.
You may use Solo software under the terms of either the Apache 2.0 license or MIT license.

Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, as defined in the Apache-2.0 license, shall be dual licensed as above, without any additional terms or conditions.

All hardware, unless otherwise noted, is dual licensed under CERN and CC-BY-SA.
You may use Solo hardware under the terms of either the CERN 1.2 license or CC-BY-SA 4.0 license.

All documentation, unless otherwise noted, is licensed under CC-BY-SA.
You may use Solo documentation under the terms of the CC-BY-SA 4.0 license


[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fsolokeys%2Fsolo.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2Fsolokeys%2Fsolo?ref=badge_large)

# Where To Buy Solo

You can buy Solo, Solo Tap, and Solo for Hackers at [solokeys.com](https://solokeys.com).

<br/>
<hr/>
<br/>

[![License](https://img.shields.io/github/license/solokeys/solo.svg)](https://github.com/solokeys/solo/blob/master/LICENSE)
[![All Contributors](https://img.shields.io/badge/all_contributors-22-orange.svg?style=flat-square)](#contributors)
[![Build Status](https://travis-ci.com/solokeys/solo.svg?branch=master)](https://travis-ci.com/solokeys/solo)
[![Discourse Users](https://img.shields.io/discourse/https/discourse.solokeys.com/users.svg)](https://discourse.solokeys.com)
[![Keybase Chat](https://img.shields.io/badge/chat-on%20keybase-brightgreen.svg)](https://keybase.io/team/solokeys.public)
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fsolokeys%2Fsolo.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2Fsolokeys%2Fsolo?ref=badge_shield)

[![latest release](https://img.shields.io/github/release/solokeys/solo.svg)](https://github.com/solokeys/solo/releases)
[![commits since last release](https://img.shields.io/github/commits-since/solokeys/solo/latest.svg)](https://github.com/solokeys/solo/commits/master)
[![last commit](https://img.shields.io/github/last-commit/solokeys/solo.svg)](https://github.com/solokeys/solo/commits/master)
[![commit activity](https://img.shields.io/github/commit-activity/m/solokeys/solo.svg)](https://github.com/solokeys/solo/commits/master)
[![contributors](https://img.shields.io/github/contributors/solokeys/solo.svg)](https://github.com/solokeys/solo/graphs/contributors)
