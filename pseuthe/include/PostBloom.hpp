/*********************************************************************
Matt Marchant 2015
http://trederia.blogspot.com

pseuthe Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

//creates a 'bloom' effect via post process

#ifndef POST_BLOOM_HPP_
#define POST_BLOOM_HPP_

#include <PostProcess.hpp>
#include <ShaderResource.hpp>

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <array>

class PostBloom final : public PostProcess
{
public:
    PostBloom();

    void apply(const sf::RenderTexture&, sf::RenderTarget&) override;

private:
    using RenderTextureArray = std::array<sf::RenderTexture, 2>;

    ShaderResource m_shaderResource;
    sf::RenderTexture m_brightnessTexture;
    RenderTextureArray m_firstPassTextures;
    RenderTextureArray m_secondPassTextures;

    void initTextures(const sf::Vector2u&);
    void filterBright(const sf::RenderTexture&, sf::RenderTexture&);
    void blurMultipass(RenderTextureArray&);
    void blur(const sf::RenderTexture&, sf::RenderTexture&, const sf::Vector2f&);
    void downSample(const sf::RenderTexture&, sf::RenderTexture&);
    void add(const sf::RenderTexture&, const sf::RenderTexture&, sf::RenderTarget&);
};

#endif //POST_BLOOM_HPP_